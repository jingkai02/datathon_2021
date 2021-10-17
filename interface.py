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
    matplotlib.use("TkAgg")
    figure_canvas_agg = FigureCanvasTkAgg(figure, canvas)
    figure_canvas_agg.draw()
    figure_canvas_agg.get_tk_widget().pack(side="top", fill="both", expand=1)
    return figure_canvas_agg

def Display(df):
    # Making the dataframe into a figure
    fig,ax = render_mpl_table(df, header_columns=0, col_width=5.0)
    fig.savefig("test.png")
    
    # Define the window layout
    layout = [
        [sg.Text("Majors")],
        [sg.Canvas(key="-CANVAS-")],
        [sg.Button("I am done")],
        #[sg.Image(size=(300, 300), key='-IMAGE-')]
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
        # Add the plot to the window
        draw_figure(window["-CANVAS-"].TKCanvas, fig)

        event, values = window.read()
        # End program if user closes window or
        # presses the OK button
        if event == "I am done" or event == sg.WIN_CLOSED:
            break

    window.close()