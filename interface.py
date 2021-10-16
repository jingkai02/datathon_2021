# -*- coding: utf-8 -*-
"""
Created on Sat Oct 16 13:04:52 2021

@author: ASUS
"""
import PySimpleGUI as sg
import numpy as np
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import matplotlib

# Insert Dataframe
matplotlib.use("TkAgg")

# Helper Function for PySimpleGui Canvas
def draw_figure(canvas, figure):
    figure_canvas_agg = FigureCanvasTkAgg(figure, canvas)
    figure_canvas_agg.draw()
    figure_canvas_agg.get_tk_widget().pack(side="top", fill="both", expand=1)
    return figure_canvas_agg

# Create Window Layout
layout = layout = [
    [sg.Text("Majors")],
    [sg.Canvas(key="-CANVAS-")],
    [sg.Button("Ok")],
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

# Create plot
fig = matplotlib.figure.Figure(figsize=(5, 4), dpi=100)
t = np.arange(0, 3, .01)
fig.add_subplot(111).plot(t, 2 * np.sin(2 * np.pi * t))

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