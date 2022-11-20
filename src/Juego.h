
#ifndef SRC_JUEGO_H_
#define SRC_JUEGO_H_
#include "Tablero.h"
#include <vector>
#include <string>

using namespace std;


typedef enum EstadoJuego {
	INICIADO,
	JUGANDO,
	CONGELADO,
	REINICIADO,
	TERMINADO
};

typedef enum TransmisionDeGenes{
	PROMEDIO,
	TRANSMISION2,
	TRANSMISION3
};

struct EstadisticasDelJuego{
	EstadoJuego estado;
	int cantidadDeTurnos;
	int turno;
	int valorDeReproduccion;
	int nacimientosTotales;
	int muertesTotales;
	int nacidasEnTurno;
	int muertasEnTurno;
};

class Juego {
private:
	Tablero* tablero;
	EstadisticasDelJuego estadisticas;
	vector<string> datosDeIngreso;
	void actualizarJuego();
public:
	static const char TERMINAR  = 'X';
	static const char SIGUIENTE = 'C';
	static const char REINICIAR = 'R';
	static const int TAMANIODELPIXEL = 1;



	Juego(int x, int y, int z);
	Juego();
	Juego(int turnos, char* configuracion);

	void mostrarTablero();
	EstadoJuego getEstado();
	Tablero* getTablero();
	void incrementarTurno();
	unsigned int getTurno();
	unsigned int getNacimientosPromedio();
	unsigned int getMuertesPromedio();
	unsigned int getNacidasEnTurno();
	unsigned int getMuertasEnTurno();
	void jugarTurno(char inputUser);

	void iniciarjuego();
	void jugarJuego();
	char pedirAccion();
	void ejecutar(char key);
	void ejecutarTurno();
	void implementarReglasSobreTablero();
	void implementarReglasSobreCasillero(Casillero* casillero);
	void avanzarTurno();
	void terminarJuego();
	void resetearEstadisticasDelJuego();
	void cargarDatosEntablero();
	void mostrarFinDeljuego();
	void mostrarEstadisticas();
	void cargarDatosDeEntrada(vector<string> &datos);


	void ImprimirDatosDeEntrada();
};

#endif /* SRC_JUEGO_H_ */
