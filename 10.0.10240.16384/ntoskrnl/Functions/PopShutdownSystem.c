// PopShutdownSystem 
 
void __noreturn PopShutdownSystem()
{
  PopNotifyShutdownListener();
  DbgUnLoadImageSymbols();
}
