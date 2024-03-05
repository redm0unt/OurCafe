FROM python:3.8-slim
RUN pip install matplotlib \
    pip install numpy

ADD python_script.py .
CMD python python_script.py

