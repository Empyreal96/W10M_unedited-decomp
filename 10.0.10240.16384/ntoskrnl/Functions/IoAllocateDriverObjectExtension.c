// IoAllocateDriverObjectExtension 
 
int __fastcall IoAllocateDriverObjectExtension(int a1, int a2, unsigned int a3, _DWORD *a4)
{
  int v5; // r6
  _BYTE *v9; // r0
  _DWORD *v10; // r4
  int v11; // r0
  _DWORD *v12; // r1
  _DWORD *v13; // r2
  int v14; // r0

  v5 = 0;
  *a4 = 0;
  if ( a3 > 0xFFFFFFF7 )
    return -1073741670;
  v9 = (_BYTE *)ExAllocatePoolWithTag(512, a3 + 8);
  v10 = v9;
  if ( !v9 )
    return -1073741670;
  memset(v9, 0, a3 + 8);
  v10[1] = a2;
  v11 = KeAcquireQueuedSpinLock(10);
  v12 = *(_DWORD **)(*(_DWORD *)(a1 + 24) + 20);
  v13 = v12;
  if ( !v12 )
    goto LABEL_4;
  do
  {
    if ( v13[1] == a2 )
      break;
    v13 = (_DWORD *)*v13;
  }
  while ( v13 );
  if ( !v13 )
  {
LABEL_4:
    *v10 = v12;
    v5 = 1;
    *(_DWORD *)(*(_DWORD *)(a1 + 24) + 20) = v10;
  }
  v14 = KeReleaseQueuedSpinLock(10, v11);
  if ( !v5 )
    return sub_5284F8(v14);
  *a4 = v10 + 2;
  return 0;
}
