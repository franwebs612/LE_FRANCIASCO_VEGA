import tensorflow as tf
import tensorflow_datasets as tfds
datos, metadatos = tfds.load('fashion_mnist', as_supervised=True, with_info=True)

datos_entrenamiento, datos_pruebas = datos ['train'], datos ['test']
nombres_clases = metadatos.features ['label'].names
nombres_clases
def normalizar(imagaenes, etiquetas):
  imagenes = tf.cast(imagenes, tf.float32)
  imagenes /= 255 #de 0/255 a 0-1
  return imagenes, etiquetas

  #Normalizamos los datos de entrenamiento y pruebas con la funcion de normalizar
  datos_entrenamiento = datos_entrenamiento.map(normalizar)
  datos_pruebas = datos_pruebas.map(normalizar)

  #Agregamos cache, para el que sea el entrenamiento sea mas rapido
  datos_entrenamiento = datos_entrenamiento.cache
  datos_pruebas = datos_pruebas.cache
  #lo vemos en imagen
for imagen, etiqueta in datos_entrenamiento.take(1):
  break
imagen = imagen.numpy().reshape((28,28))
import matplotlib.pyplot as plt

  #dibujamos
plt.figure()
plt.imshow(imagen, cmap=plt.cm.binary)
plt.colorbar()
plt.grid(False)
plt.show()
modelo = tf.keras.Sequential([
    tf.keras.layers.Flatten(input_shape=(28,28,1)),
    tf.keras.layers.Dense(50, activation=tf.nn.relu),
    tf.keras.layers.Dense(50, activation=tf.nn.relu),
    tf.keras.layers.Dense(10, activation=tf.nn.softmax)
    modelo.compile(
    optimizer = 'adam',
    loss = tf.keras.losses.SparseCategoricalCrossentropy(),
    metrics = ['accuracy']
)
num_ej_entrenamiento = metadatos.splits['train'].num_examples
num_ej_pruebas = metadatos.splits ['test'].num_examples

print(num_ej_entrenamiento)
print(num_ej_pruebas)
#usamos lotes para optimizar el entrenamiento debido a la gran cantidad de imagenes que tenemos
lotes = 32
datos_entrenamiento = datos_entrenamiento.repeat().shuffle(60000).batch(lotes)
datos_pruebas = datos_pruebas.batch(lotes)
import math

historial = modelo.fit(datos_entrenamiento, epochs=5, steps_per_epoch= math.ceil(num_ej_entrenamiento/lotes))
import numpy as np

for imagenes_prueba, etiquetas_prueba in datos_pruebas.take(1):
  imagenes_prueba = imagenes_prueba.numpy()
  etiquetas_prueba = etiquetas_prueba.numpy()
  predicciones = modelo.predict(imagenes_prueba)
  imagen = imagenes_prueba[28]
imagen = np.array([imagen])
prediccion = modelo.predict(imagen)

print("predict" + nombres_clases[np.argmax(prediccion[0])])