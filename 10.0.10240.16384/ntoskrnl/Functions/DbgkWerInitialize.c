// DbgkWerInitialize 
 
void DbgkWerInitialize()
{
  if ( !DbgkpWerInitialized )
  {
    __dmb(0xBu);
    DbgkpBusy = 0;
    DbgkpWerDefaultPolicy = 2;
    DbgkpWerDeferredWriteTimeoutSeconds = 600;
    DbgkpWerInitialized = 1;
  }
}
