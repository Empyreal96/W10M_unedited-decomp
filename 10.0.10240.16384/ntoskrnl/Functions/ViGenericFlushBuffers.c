// ViGenericFlushBuffers 
 
int __fastcall ViGenericFlushBuffers(int a1, int a2)
{
  return ViGenericDispatchHandler(a1, a2, (int (*)(void))pXdvIRP_MJ_FLUSH_BUFFERS, 9);
}
