// PiSwGetChildPdo 
 
int __fastcall PiSwGetChildPdo(int a1, int a2)
{
  unsigned int *v2; // r5
  int v4; // r4
  int v5; // r0
  int v6; // r2
  unsigned int v7; // r3
  int v9; // r0
  unsigned int **v10; // r6
  unsigned int v11; // r2
  int v12[6]; // [sp+10h] [bp-18h] BYREF

  v2 = (unsigned int *)(a2 - 52);
  v4 = 0;
  v12[0] = 0;
  v5 = PiSwFindPdoAssociation(a2 - 52, a1, 1);
  if ( (v2[1] & 2) != 0 )
  {
    if ( !v5 )
      return v4;
    v6 = *(_DWORD *)(*(_DWORD *)(v5 + 12) + 40);
    v7 = *(_DWORD *)(v6 + 4) & 0xFFFFFFF7;
    goto LABEL_4;
  }
  if ( v5 )
  {
    v4 = *(_DWORD *)(v5 + 12);
    v6 = *(_DWORD *)(v4 + 40);
    v7 = *(_DWORD *)(v6 + 4) | 8;
LABEL_4:
    *(_DWORD *)(v6 + 4) = v7;
LABEL_5:
    if ( v4 )
      ObfReferenceObject(v4);
    return v4;
  }
  if ( v2[16] )
    PiSwMakePdoInactive();
  v9 = IoCreateDevice(PiSwDeviceDriverObject, 8, 0, 34, 128, 0, v12);
  v4 = v12[0];
  if ( v9 < 0 )
    goto LABEL_5;
  v10 = *(unsigned int ***)(v12[0] + 40);
  *v10 = 0;
  v10[1] = 0;
  if ( !v2[20] )
  {
    *v10 = v2;
    __dmb(0xBu);
    do
      v11 = __ldrex(v2);
    while ( __strex(v11 + 1, v2) );
    __dmb(0xBu);
    v2[16] = v4;
    v10[1] = (unsigned int *)((unsigned int)v10[1] | 8);
    *(_DWORD *)(v4 + 28) &= 0xFFFFFF7F;
    PiSwAddPdoAssociation(v2, a1, v4);
    goto LABEL_5;
  }
  return sub_7EE330();
}
