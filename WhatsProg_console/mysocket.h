#ifndef _MYSOCKET_H_
#define _MYSOCKET_H_

#include <iostream>
#include <string>

/* #############################################################
   ##  ATENCAO: VOCE DEVE DESCOMENTAR UM DOS BLOCOS ABAIXO    ##
   ##  PARA PODER COMPILAR NO WINDOWS OU NO LINUX             ##
   ############################################################# */

/// Descomente o bloco a seguir para compilar no Windows

///*

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x601  // Windows 7
#endif // _WIN32_WINNT


// Os arquivos de inclusao para utilizacao dos sockets basicos
#include <winsock2.h>
#include <ws2tcpip.h>

// O tipo que representa o socket basico do sistema operacional
// O Windows jah define um tipo SOCKET;

// O valor que representa um erro no socket basico
// O Windows jah define a constante SOCKET_ERROR

// O valor que representa um socket basico invalido
// O Windowas jah define a constante INVALID_SOCKET

//*/

/// Descomente o bloco a seguir para compilar no Linux

/*

// Os arquivos de inclusao para utilizacao dos sockets basicos
#include <sys/socket.h>

// O tipo que representa o socket basico do sistema operacional
typedef int SOCKET;

// O valor que representa um erro no socket basico
#define SOCKET_ERROR -1

// O valor que representa um socket basico invalido
#define INVALID_SOCKET -1

*/

typedef enum
{
  // O valor de retorno em caso de sucesso
  MYSOCKET_OK=0,
  // O valor de retorno em caso de erro
  MYSOCKET_ERROR=-1,
  // Valor de retorno quando o outro socket encerrou a conexao corretamente
  MYSOCKET_DISCONNECTED=-666,
  // Valor de retorno em caso de timeout
  MYSOCKET_TIMEOUT=-999
} MYSOCKET_STATUS;


// Tamanho maximo das strings enviadas pela classe mysocket
#define MYSOCKET_TAM_MAX_STRING 256

// Predefinicao das classes
class mysocket_queue;
class tcp_mysocket;
class tcp_mysocket_server;

/* #############################################################
   ##  A classe base dos sockets                              ##
   ############################################################# */

class mysocket
{
private:

  SOCKET id;

public:
  /// A funcao de inicializacao da biblioteca de sockets
  static MYSOCKET_STATUS init();

  /// A funcao de encerramento da biblioteca de sockets
  static void end();

  /// Construtor por default
  inline mysocket(): id(INVALID_SOCKET) {}

  /// Permuta dois sockets
  /// Geralmente, deve ser utilizado ao inves do operador de atribuicao
  void swap(mysocket &S);

  /// Fecha (caso esteja aberto) um socket
  void close();

  /// Testa se um socket eh "virgem" ou foi fechado
  inline bool closed() const {return id==INVALID_SOCKET;}
  /// Testa se um socket estah aberto (aceitando conexoes)
  inline bool accepting() const {return !closed();}
  /// Testa se um socket estah conectado (pronto para ler e escrever)
  inline bool connected() const {return !closed();}

  /// Imprime um socket
  friend std::ostream& operator<<(std::ostream& os, const mysocket &);

  /// As classes amigas
  friend class tcp_mysocket;
  friend class tcp_mysocket_server;
  friend class mysocket_queue;
};

/* #############################################################
   ##  As classes dos sockets orientados a conexao (TCP)      ##
   ############################################################# */

class tcp_mysocket: public mysocket
{
public:

  /// Construtor default
  inline tcp_mysocket(): mysocket() {}

  /// Se conecta a um socket aberto
  /// Soh pode ser usado em sockets "virgens" ou explicitamente fechados
  /// Retorna MYSOCKET_OK, se tudo deu certo, ou MYSOCKET_ERRO
  MYSOCKET_STATUS connect(const char *name, const char *port);

  /// Leh de um socket conectado
  /// Soh pode ser usado em socket para o qual tenha sido feito um "connect" antes
  /// Ou entao em um socket retornado pelo "accept" de um socket servidor
  /// O ultimo parametro eh o tempo maximo (em milisegundos) para esperar
  /// por dados; se for <0, que eh o default, espera indefinidamente.
  /// Retorna:
  /// - MYSOCKET_OK, em caso de sucesso;
  /// - MYSOCKET_TIMEOUT, se retornou por timeout;
  /// - MYSOCKET_DISCONNECTED, se a conexao foi fechada corretamente; ou
  /// - MYSOCKET_ERRO, em caso de erro
  MYSOCKET_STATUS read(char *dado, size_t len, long milisec=-1) const;

  /// Escreve em um socket conectado
  /// Soh pode ser usado em socket para o qual tenha sido feito um "connect" antes
  /// Ou entao em um socket retornado pelo "accept" de um socket servidor
  /// Retorna:
  /// - MYSOCKET_OK, em caso de sucesso;
  /// - MYSOCKET_ERRO, em caso de erro
  MYSOCKET_STATUS write(const char* dado, size_t len) const;

  /// Leh um int32_t de um socket conectado
  /// O ultimo parametro eh o tempo maximo (em milisegundos) para esperar
  /// por dados; se for <0, que eh o default, espera indefinidamente.
  /// Retorna:
  /// - MYSOCKET_OK, em caso de sucesso;
  /// - MYSOCKET_TIMEOUT, se retornou por timeout;
  /// - MYSOCKET_DISCONNECTED, se a conexao foi fechada corretamente; ou
  /// - MYSOCKET_ERRO, em caso de erro
  MYSOCKET_STATUS read_int(int32_t &num, long milisec=-1) const;

  /// Escreve um int32_t em um socket conectado
  /// Retorna:
  /// - MYSOCKET_OK, em caso de sucesso;
  /// - MYSOCKET_ERRO, em caso de erro
  MYSOCKET_STATUS write_int(const int32_t num) const;

  /// Leh uma string de um socket conectado
  /// Primeiro leh o numero de bytes da string (int32_T), depois os caracteres
  /// O ultimo parametro eh o tempo maximo (em milisegundos) para esperar
  /// por dados; se for <0, que eh o default, espera indefinidamente.
  /// Retorna:
  /// - MYSOCKET_OK, em caso de sucesso;
  /// - MYSOCKET_TIMEOUT, se retornou por timeout;
  /// - MYSOCKET_DISCONNECTED, se a conexao foi fechada corretamente; ou
  /// - MYSOCKET_ERRO, em caso de erro
  MYSOCKET_STATUS read_string(std::string &msg, long milisec=-1) const;

  /// Escreve uma string em um socket conectado
  /// Primeiro escreve o numero de bytes da string (int32_T), depois os caracteres
  /// Retorna:
  /// - MYSOCKET_OK, em caso de sucesso;
  /// - MYSOCKET_ERRO, em caso de erro
  MYSOCKET_STATUS write_string(const std::string &msg) const;

};

class tcp_mysocket_server: public mysocket
{
public:

  /// Construtor default
  inline tcp_mysocket_server(): mysocket() {}

  /// Abre um novo socket para esperar conexoes
  /// Soh pode ser usado em sockets "virgens" ou explicitamente fechados
  /// Retorna MYSOCKET_OK ou MYSOCKET_ERRO
  MYSOCKET_STATUS listen(const char *port, int nconex=1);

  /// Aceita uma conexao que chegou em um socket aberto
  /// Soh pode ser usado em socket para o qual tenha sido feito um "listen" antes
  /// O socket "a" passado como parametro, em caso de sucesso, estarah conectado
  /// (nao-conectado em caso de erro)
  /// Retorna MYSOCKET_OK ou MYSOCKET_ERRO
  MYSOCKET_STATUS accept(tcp_mysocket &a) const;

};

/* #############################################################
   ##  A fila de sockets                                      ##
   ############################################################# */

class mysocket_queue
{
 private:

  fd_set set;

  /// O valor da maior_id+1 de todos os sockets inseridos na fila de sockets
  /// O select do Unix utiliza esse valor e soh monitora os sockets ateh essa id
  /// O select do Windows ignora esse valor
  SOCKET nfds;

  /// Construtor por copia
  /// NUNCA DEVE SER CHAMADO OU UTILIZADO
  mysocket_queue(const mysocket_queue &S);

  /// Operador de atribuicao
  /// NUNCA DEVE SER CHAMADO OU UTILIZADO
  void operator=(const mysocket_queue &S);

 public:
  /// Limpa a lista de sockets
  void clean();

  /// Construtor e destrutor
  inline mysocket_queue() {clean();}
  inline ~mysocket_queue() {clean();}

  /// Adiciona um socket a uma fila de sockets
  /// Retorna MYSOCKET_OK ou MYSOCKET_ERRO
  MYSOCKET_STATUS include(const mysocket &a);

  /// Retira um socket de uma fila de sockets
  /// Retorna MYSOCKET_OK ou MYSOCKET_ERRO
  MYSOCKET_STATUS exclude(const mysocket &a);

  /// Bloqueia ateh haver alguma atividade de leitura em socket da fila
  /// Retorna:
  /// - MYSOCKET_OK, caso haja dados a serem lidos (sucesso);
  /// - MYSOCKET_TIMEOUT, se retornou por timeout; ou
  /// - MYSOCKET_ERRO, em caso de erro
  MYSOCKET_STATUS wait_read(long milisec=-1);

  /// Bloqueia ateh haver alguma atividade de conexao em socket da fila
  /// Retorna:
  /// - MYSOCKET_OK, caso haja dados a serem lidos (sucesso);
  /// - MYSOCKET_TIMEOUT, se retornou por timeout; ou
  /// - MYSOCKET_ERRO, em caso de erro
  inline MYSOCKET_STATUS wait_connect(long milisec=-1) {return wait_read(milisec);}

  /// Bloqueia ateh haver alguma atividade de escrita em socket da fila
  /// Retorna:
  /// - MYSOCKET_OK, caso haja dados a serem lidos (sucesso);
  /// - MYSOCKET_TIMEOUT, se retornou por timeout; ou
  /// - MYSOCKET_ERRO, em caso de erro
  MYSOCKET_STATUS wait_write(long milisec=-1);

  /// Testa se houve atividade em um socket especifico da fila
  bool had_activity(const mysocket &a);

};

#endif
