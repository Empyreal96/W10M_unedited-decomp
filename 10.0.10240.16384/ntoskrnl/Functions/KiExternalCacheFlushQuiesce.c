// KiExternalCacheFlushQuiesce 
 
void KiExternalCacheFlushQuiesce()
{
  while ( KiExternalCacheFlushOutstanding )
    __yield();
}
