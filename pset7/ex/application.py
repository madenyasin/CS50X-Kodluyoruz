From flask import Flask

app = Flask(__name__)

def index():
    return "You are at the index page!"
def sample():
    return "You are on the sample page!"