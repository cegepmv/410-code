const express = require('express');
const { Gpio } = require('onoff');
const btn = new Gpio(23,'in');
const led = new Gpio(18,'out');
const ledR = new Gpio(17, 'out');
const ledG = new Gpio(27, 'out');
const ledB = new Gpio(22, 'out');
const cors = require('cors');
const app = express();
const port = 3000;

var ledState;

app.use(express.json());
app.use(cors());

// Initialisation
ledR.writeSync(1);
ledG.writeSync(1);
ledB.writeSync(1);

app.get('/', (req, res) => {
  res.send('Bonjour le monde!')
});

// Retourne le JSON { state: 1 } ou { state: 0 }
app.get('/getBTN', (req, res) => {
  const bouton = {
    "state": BTN.readSync() // Lire la valeur 
  };
  res.send(bouton);
});

app.post('/setLED', (req, res) => {
  const { state } = req.body;
  if (state !== 0 && state !== 1) {
    return res.status(400).json({ message: 'Erreur: valeur différente de 0 ou 1' });
  }
  console.log(state);
  led.writeSync(state);
});

app.post('/setRGB', (req, res) => {
  const { state } = req.body;
  console.log(state);
  switch (state) {
    case "red":
      ledR.write(0);
      ledG.write(1);
      ledB.write(1);
      ledState = state;
      break;
    case "green":
      ledR.write(1);
      ledG.write(0);
      ledB.write(1);
      ledState = state;
      break;
    case "blue":
      ledR.write(1);
      ledG.write(1);
      ledB.write(0);
      ledState = state;
      break;
    case "shut":
      ledR.write(1);
      ledG.write(1);
      ledB.write(1);
      ledState = state;
      break;
    default:
      return res.status(400).json({ message: 'Erreur: données JSON invalides.' });
  }
});

app.get('/getRGB', (req, res) => {
  const etat = {
    "state": ledState
  };
  res.send(etat);
});

app.listen(port, () => {
  console.log(`Application roule sur port ${port}`)
})