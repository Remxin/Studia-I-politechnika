import keyring
import json

class KeyringMgr:
    def __init__(self):
        self.dataLoaded = False
        self.data = []

        data = keyring.get_password("PYMGR", "")
        print(data)
        if not data:
            return
        
        datajson = json.load(data)
        self.data = datajson

    def addRecord(self, key: str, val: str):
        keyring.set_password(key, "", val)


    def __del__(self):
        print("bye")
        encodedData = json.dumps(self.data, separators=(',', ':'))
        print(type(encodedData))
        keyring.set_password("PYMGR", 'dustin', 'my secret password')
        
        




