import bcrypt

class FileMgr:
    def __init__(self):
        self.file = None

    def openFile(self, filePath):
        self.file = open(filePath, "r+")

    def encrypt(self, string: str) -> str:
        bytes = string.encode("utf-8")
        salt = bcrypt.gensalt()
        hash = bcrypt.hashpw(bytes, salt)
        return hash
    
    def decrypt(self, userInput: str, hash: str) -> bool:
        userBytes =userInput.encode("utf-8")
        result = bcrypt.checkpw(userBytes, hash) 
        return result
    
    def addField(self, key: str, value: str):
        hashedVal = self.encrypt(value)
        self.file.write(f'{key}:{hashedVal}\n')

    def __del__(self):
        self.file.close()