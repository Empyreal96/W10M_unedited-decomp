// KiInitializeDynamicProcessorDpc 
 
int __fastcall KiInitializeDynamicProcessorDpc(int a1, _DWORD **a2, unsigned int *a3, unsigned int *a4)
{
  int v6; // r1
  int v7; // r6
  unsigned int v8; // r2
  int v9; // r3
  int v10; // r3
  int result; // r0
  unsigned int v12; // r2
  __int16 v13[2]; // [sp+8h] [bp-20h] BYREF
  int v14; // [sp+Ch] [bp-1Ch]
  int v15; // [sp+10h] [bp-18h]

  if ( KeSignalCallDpcSynchronize(a4) )
  {
    KiUpdateNumberProcessors((*a2)[5]);
    KiInitializeProcessor((int)*a2, v6);
    KiConfigureProcessorBlock(*a2);
    KeSetAffinityProcess(PsInitialSystemProcess, 0, &KeActiveProcessors);
    v13[0] = 1;
    v13[1] = 1;
    v14 = 0;
    v15 = 1 << (*a2)[5];
    v7 = KfRaiseIrql(12);
    KiIpiSendPacket(0, (int)v13, (int)PopPoCoalescinCallback, 0, 0, 0);
    v8 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    while ( 1 )
    {
      v10 = *(_DWORD *)(v8 + 2944);
      __dmb(0xBu);
      if ( !v10 )
        break;
      __dmb(0xAu);
      __yield();
    }
    KfLowerIrql(v7);
    off_617A00(0, *a2 + 5);
    KiConfigureSchedulingInformation((int)*a2, 1);
    __dmb(0xBu);
    KiBarrierWait = 0;
    __dmb(0xBu);
    *((_BYTE *)a2 + 4) = 1;
  }
  else
  {
    while ( 1 )
    {
      v9 = *((unsigned __int8 *)a2 + 4);
      __dmb(0xBu);
      if ( v9 )
        break;
      __dmb(0xAu);
      __yield();
    }
  }
  result = KiConfigureSchedulingInformation(((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408, 1);
  __dmb(0xBu);
  do
    v12 = __ldrex(a3);
  while ( __strex(v12 - 1, a3) );
  __dmb(0xBu);
  return result;
}
