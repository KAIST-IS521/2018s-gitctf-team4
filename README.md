# 2018s-gitctf-team4


### Overview

Welcome, IS521 students!

Our service is an HTTP web server.

To test our service, first run docker.
```
git clone <repository>
cd <repository>
./setup.sh team4 4000 4000
```

Then open your browser to navigate to our web server:
```
https://localhost:4000
```

You will see a warm greeting message.

Or, you can use the fancy ```gitctf-script```:
```
./gitctf.py exec service --service-dir <repository> --service-name test-service --host-port 4000 --service-port 4000
```

**Alright then,**
### Happy Hacking!!