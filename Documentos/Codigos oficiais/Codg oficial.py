from bluetooth import *
import sys
import speech_recognition as sr
from gtts import gTTS
from playsound import playsound
import serial
import time

bluetooth = serial.Serial('COM7', 9600)

pos = 0;

        #Funcao responsavel por falar 
def cria_audio(audio):
        tts = gTTS(audio,lang='pt-br')
        #Salva o arquivo de audio
        tts.save('audios/hello.mp3')
        print("Estou aprendendo o que você disse...")
        #Da play ao audio
        playsound('audios/hello.mp3')
            
while pos >= 0:
        #Funcao responsavel por ouvir e reconhecer a fala
        def ouvir_microfone():
                #Habilita o microfone para ouvir o usuario
                microfone = sr.Recognizer()
                with sr.Microphone() as source:
                        #Chama a funcao de reducao de ruido disponivel na speech_recognition
                        microfone.adjust_for_ambient_noise(source)
                        #Avisa ao usuario que esta pronto para ouvir
                        print("Diga alguma coisa: ")
                        time.sleep(0.5)
                        #Armazena a informacao de audio na variavel
                        audio = microfone.listen(source)
                        

                try:
                        #Passa o audio para o reconhecedor de padroes do speech_recognition
                        frase = microfone.recognize_google(audio,language='pt-BR')

                        #Após alguns segundos, retorna a frase falada
                        #print("Você disse: " + frase)

                        if frase == 'andar':
                           bluetooth.write(b's')
                           print(frase)
                                                                               
                        elif frase == 'esquerda':
                           print(frase)
                           bluetooth.write(b'a')
                           
                        elif frase == 'direita':
                           print(frase)
                           bluetooth.write(b'd')
                           
                        elif frase == 'marcha':
                           print(frase)
                           bluetooth.write(b'w')
                           
                #Caso nao tenha reconhecido o padrao de fala, exibe esta mensagem
                except sr.UnknownValueError:
                      print("Não entendi")

          
        
     
                
     
        frase = ouvir_microfone()

pos =  2
