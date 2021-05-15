// KiGenericCallDpcWorker 
 
int __fastcall KiGenericCallDpcWorker(int a1, _DWORD *a2)
{
  int v4; // r5
  int *v5; // r8
  int v6; // r9
  int v7; // t1
  int v9; // [sp+8h] [bp-30h] BYREF
  _DWORD v10[10]; // [sp+10h] [bp-28h] BYREF

  v4 = KfRaiseIrql(2);
  v9 = KeNumberProcessors_0;
  v10[0] = KeNumberProcessors_0;
  v10[1] = KeNumberProcessors_0;
  if ( (unsigned int)KeNumberProcessors_0 > 1 )
  {
    v5 = &dword_681D84;
    v6 = KeNumberProcessors_0 - 1;
    do
    {
      v7 = *v5++;
      *(_DWORD *)(v7 + 1824) = *a2;
      *(_DWORD *)(v7 + 1828) = a2[1];
      KiInsertQueueDpc(v7 + 1812);
      --v6;
    }
    while ( v6 );
  }
  ((void (__fastcall *)(int, _DWORD, int *, _DWORD *))*a2)(a1 + 1812, a2[1], &v9, v10);
  while ( v9 )
  {
    __dmb(0xAu);
    __yield();
  }
  __dmb(0xBu);
  return KfLowerIrql(v4);
}
