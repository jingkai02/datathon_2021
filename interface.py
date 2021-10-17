# -*- coding: utf-8 -*-
"""
Created on Sat Oct 16 13:04:52 2021

@author: ASUS
"""
import PySimpleGUI as sg
import numpy as np
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import matplotlib
import matplotlib.pyplot as plt


#Redering pandas Dataframe into Matplotlib Figure
def render_mpl_table(data, col_width=3.0, row_height=0.625, font_size=14,
                     header_color='#40466e', row_colors=['#f1f1f2', 'w'], edge_color='w',
                     bbox=[0, 0, 1, 1], header_columns=0,
                     ax=None, **kwargs):
    if ax is None:
        size = (np.array(data.shape[::-1]) + np.array([0, 1])) * np.array([col_width, row_height])
        fig, ax = plt.subplots(figsize=size)
        ax.axis('off')
    mpl_table = ax.table(cellText=data.values, bbox=bbox, colLabels=data.columns, **kwargs)
    mpl_table.auto_set_font_size(False)
    mpl_table.set_fontsize(font_size)

    for k, cell in mpl_table._cells.items():
        cell.set_edgecolor(edge_color)
        if k[0] == 0 or k[1] < header_columns:
            cell.set_text_props(weight='bold', color='w')
            cell.set_facecolor(header_color)
        else:
            cell.set_facecolor(row_colors[k[0]%len(row_colors) ])
    return ax.get_figure(), ax


# Helper Function for PySimpleGui Canvas
def draw_figure(canvas, figure):
    figure_canvas_agg = FigureCanvasTkAgg(figure, canvas)
    figure_canvas_agg.draw()
    figure_canvas_agg.get_tk_widget().pack(side="top", fill="both", expand=1)
    return figure_canvas_agg

# Function that makes the display window
def Display(df):
    matplotlib.use("TkAgg")
    
    # Making the dataframe into a figure
    fig,ax = render_mpl_table(df, header_columns=0, col_width=5.0)
    fig.savefig("test.png")
    
    # Define the window layout
    layout = [
        [sg.Text("What majors are you interested in?")],
        [sg.Text('Major1', size =(15, 1)), sg.InputText()],
        [sg.Text('Major2', size =(15, 1)), sg.InputText()],
        [sg.Text(size=(40,1), key='-OUTPUT-')],
        [sg.Canvas(key="-CANVAS-")],
        [sg.Button('Ok'), sg.Button('Quit')]
    ]

    # Create the form and show it without the plot
    window = sg.Window(
        "Matplotlib Single Graph",
        layout,
        location=(0, 0),
        finalize=True,
        element_justification="center",
        font="Helvetica 18",
    )

    # Create an event loop
    while True:
        event, values = window.read()
        
        # Add the plot to the window
        draw_figure(window["-CANVAS-"].TKCanvas, fig)

        # End program if user closes window or
        # presses the OK button
        if event == sg.WINDOW_CLOSED or event == 'Quit':
            break
            
        # Output a message to the window
        window['-OUTPUT-'].update(values[0] +" "+ values[1] + " has the following classes.")
        
    # Finish up by removing from the screen
    window.close()
    