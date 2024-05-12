from classes.App import App
from classes.FileMgr import FileMgr
from classes.KeyringMgr import KeyringMgr

from tkinter import *


def main():
    # fileMgr = FileMgr()
    keyringMgr = KeyringMgr()
    app = App(keyringMgr)

    

if __name__ == "__main__":
    main()