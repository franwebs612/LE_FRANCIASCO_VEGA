import tensorflow as tf
import numpy as np
centimetros = np.array([500, 1000, 2000, 3000 , 6000 , 10000, 50000], dtype=float)
metros = np.array([ 5, 10, 20, 30, 60, 100, 500], dtype=float)
#keras = framework para hacer la red neuronal de manera mas simple
#capas densas = son las que tienen conexiones desde cada neuronas a todas las otras neuronas de la siguente capa.
#innput shape = indicamos que tenemos una entrada con una neurona
capa = tf.keras.layers.Dense(units =1, input_shape=[1])  
modelo = tf.keras.Sequential([capa])
#ahora le decimos como queremos que procese la informacion para aprender mejor
#Adam lo utilizamos para que vaya ajustando de celsisus a fahrenheit en este caso, le tendremos que asginar un valor de que tanto queremos que vaya ajustando los resultados.
modelo.compile(
    optimizer = tf.keras.optimizers.Adam(0.1),
    loss= 'mean_squared_error'
)
#Ahora lo entrenamos.
#modelo.fit= le indicamos los valores de entrada y resultados esperados.
#epochs= cuantas vueltas queremos que lo intente, mientras mas, mas se optimiza.
print("Entramiento..")
historial = modelo.fit(centimetros, metros, epochs =1000, verbose = False)
print ("MODELO ENTRENADO")
import matplotlib.pyplot as plt
plt.xlabel("#Epoca")
plt.ylabel("Magnitud de perdida")
plt.plot(historial.history["loss"])
print("Prediccion")
resultado = modelo.predict([100000.0])
print("El resultado es "+str(resultado)+"metros")