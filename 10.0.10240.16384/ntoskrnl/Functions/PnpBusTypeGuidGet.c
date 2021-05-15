// PnpBusTypeGuidGet 
 
int __fastcall PnpBusTypeGuidGet(unsigned int a1, _DWORD *a2)
{
  int v4; // r4
  int v5; // r0
  unsigned __int8 v6; // r6
  unsigned int v7; // r2
  _DWORD *v9; // r4
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r4
  unsigned int v14; // r1

  v4 = KeAbPreAcquire((unsigned int)&PnpBusTypeGuidLock, 0, 0);
  v5 = KfRaiseIrql(1);
  v6 = v5;
  do
    v7 = __ldrex((unsigned __int8 *)&PnpBusTypeGuidLock);
  while ( __strex(v7 & 0xFE, (unsigned __int8 *)&PnpBusTypeGuidLock) );
  __dmb(0xBu);
  if ( (v7 & 1) == 0 )
    return sub_7F0494();
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  dword_630C64 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_630C7C = v5;
  if ( a1 >= PnpBusTypeGuidCount )
  {
    v13 = -1073741772;
  }
  else
  {
    v9 = (_DWORD *)(PnpBusTypeGuidArray + 16 * a1);
    v10 = v9[1];
    v11 = v9[2];
    v12 = v9[3];
    *a2 = *v9;
    a2[1] = v10;
    a2[2] = v11;
    a2[3] = v12;
    v13 = 0;
  }
  dword_630C64 = 0;
  __dmb(0xBu);
  do
    v14 = __ldrex((unsigned int *)&PnpBusTypeGuidLock);
  while ( !v14 && __strex(1u, (unsigned int *)&PnpBusTypeGuidLock) );
  if ( v14 )
    ExpReleaseFastMutexContended((unsigned int *)&PnpBusTypeGuidLock, v14);
  KfLowerIrql(v6);
  KeAbPostRelease((unsigned int)&PnpBusTypeGuidLock);
  return v13;
}
