public class ServerSideInternetModule {
    void serverStart() {
        // Определяем номер порта, который будет "слушать" сервер
               int port = 1777;

               try {
                   // Открыть серверный сокет (ServerSocket)
                   // Это специальный класс для сетевого взаимодействия с серверной стороны
                   ServerSocket servSocket = new ServerSocket(port);

                   // Входим в бесконечный цикл - ожидаем соединения
                   while (true) {
                       System.out.println("Waiting for a connection on " + port);

                       // Получив соединение начинаем работать с сокетом
                       Socket fromClientSocket = servSocket.accept();

                       // Работаем с потоками ввода-вывода
                       try (Socket localSocket = fromClientSocket;
                            PrintWriter pw = new PrintWriter(localSocket.getOutputStream(), true);
                            BufferedReader br = new BufferedReader(new InputStreamReader(localSocket.getInputStream()))) {

                           // Читаем сообщения от клиента до тех пор пока он не скажет "bye"
                           String str;
                           while ((str = br.readLine()) != null) {
                               // Печатаем сообщение
                               System.out.println("The message: " + str);

                               // Сравниваем с "bye" и если это так - выходим из цикла
                               if (str.equals("bye")) {
                                   // Тоже говорим клиенту "bye" и выходим из цикла
                                   pw.println("bye");
                                   break;
                               } else {
                                   // Посылаем клиенту ответ
                                   str = "Server returns: " + str;
                                   pw.println(str);
                               }
                           }
                       } catch (IOException ex) {
                           ex.printStackTrace(System.out);
                       }
                   }
               } catch (IOException ex) {
                   ex.printStackTrace(System.out);
               }
    }
}
