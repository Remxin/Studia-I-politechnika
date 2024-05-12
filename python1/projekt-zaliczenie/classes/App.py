import tkinter as tk
from tkinter import filedialog
from classes.FileMgr import FileMgr
from classes.KeyringMgr import KeyringMgr

class App:
    def __init__(self, keyringMgr: KeyringMgr):
        # self.fileMgr = fileMgr
        self.keyringMgr = keyringMgr

        self.window = tk.Tk()
        self.makeApp()
        
    def makeApp(self):
        self.window.geometry("500x500")
        self.createLabel("Python password manager", 24)
        self.createBtn("select file", self.openSelectFilePopUp)
        self.window.mainloop()

    def createLabel(self, text: str, size):
        label = tk.Label(text=text, font=("Arial", size))
        label.pack()

    def createBtn(self, text: str, onclick):
        btn = tk.Button(text=text, command=onclick, width=12, height=4)
        btn.pack()

    def openSelectFilePopUp(self):
        filetypes = [('all files', '.*'), ('text files', '.txt')]
        filepath = filedialog.askopenfilename(initialdir = "./",
                                          title = "Select password file",
                                          filetypes=filetypes
                                          )
        # self.fileMgr.openFile(filepath)
        
