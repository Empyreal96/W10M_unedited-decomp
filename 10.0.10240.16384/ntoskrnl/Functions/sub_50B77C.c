// sub_50B77C 
 
void sub_50B77C()
{
  int v0; // r4

  ExpHotAddProcessorToWorkers(v0);
  *(_DWORD *)(v0 + 18236) = *(_DWORD *)(ExSaPageArrays + 4 * *(_DWORD *)(v0 + 20));
  JUMPOUT(0x463CA4);
}
