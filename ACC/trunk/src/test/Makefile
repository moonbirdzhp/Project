CPP = g++
LIBPATH = /home/moon/MyLib/lib/
LIBS = ACE
INCLUDE = /home/moon/MyLib/include/
SERVER = ServiceHandler.cpp ReactorServer.cpp
CLIENT = ClientHandler.cpp ReactorClient.cpp
ASYNSERVER = AsynServiceHandler.cpp ReactorAsynServer.cpp
TASKCLIENT = ClientTaskHandler.cpp ReactorTaskClient.cpp
MUTEXTEST = ThreadMutex.cpp DeviceRepository.cpp RepositoryVisitor.cpp
CONFIG_TEST = Config_Test.cpp
server : $(SERVER)
	$(CPP) $(SERVER) -L $(LIBSPATH) -l$(LIBS) -I $(INCLUDE) -o server
client : $(CLIENT)
	$(CPP) $(CLIENT) -L $(LIBPATH) -l$(LIBS) -I $(INCLUDE) -o client
asynserver : $(ASYNSERVER)
	$(CPP) $(ASYNSERVER) -L $(LIBPATH) -l$(LIBS) -I $(INCLUDE) -o asynserver
taskclient : $(TASKCLIENT)
	$(CPP) $(TASKCLIENT) -L $(LIBPATH) -l$(LIBS) -I $(INCLUDE) -o taskclient
mutextest : $(MUTEXTEST)
	$(CPP) $(MUTEXTEST) -L $(LIBPATH) -l$(LIBS) -I $(INCLUDE) -o mutextest
config : $(CONFIG_TEST)
	$(CPP) $(CONFIG_TEST) -L $(LIBPATH) -l$(LIBS) -I $(INCLUDE) -o config
