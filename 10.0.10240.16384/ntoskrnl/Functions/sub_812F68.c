// sub_812F68 
 
void __fastcall sub_812F68(int a1, int a2, int a3, int a4, int a5, unsigned int *a6)
{
  int v6; // r5
  unsigned int *v7; // r6
  int v8; // r7
  _DWORD *v9; // r8
  unsigned int *v10; // r9
  unsigned int v11; // r10
  unsigned int v12; // r5
  int v13; // r7
  int v14; // r8
  unsigned int v15; // r4
  int *v16; // r2
  int v17; // t1
  int *v18; // r0
  int *v19; // r6
  unsigned int *v20; // r3

  if ( v6 < 0 )
    goto LABEL_20;
  BcdDeleteElement(v8);
  if ( BiTranslateObjectIdentifier(v9, v11, &a5) < 0 )
    goto LABEL_21;
  v12 = *v7;
  v13 = *v10;
  v14 = a5;
  v15 = 0;
  if ( *v7 )
  {
    v16 = (int *)*v10;
    do
    {
      v17 = *v16++;
      if ( v17 == a5 )
        break;
      ++v15;
    }
    while ( v15 < v12 );
    if ( v15 )
    {
      if ( v15 != v12 )
        goto LABEL_12;
    }
    else if ( v12 )
    {
      goto LABEL_21;
    }
  }
  ++v12;
LABEL_12:
  v18 = (int *)ExAllocatePoolWithTag(1, 4 * v12, 1262764866);
  v19 = v18;
  if ( v18 )
  {
    *v18 = v14;
    if ( v15 )
      memmove((int)(v18 + 1), v13, 4 * v15);
    if ( v15 < v12 - 1 )
      memmove((int)&v19[v15 + 1], v13 + 4 * v15 + 4, 4 * (v12 - v15 - 1));
    if ( *v10 )
      ExFreePoolWithTag(*v10);
    v20 = a6;
    *v10 = (unsigned int)v19;
    *v20 = v12;
LABEL_21:
    JUMPOUT(0x7A473C);
  }
LABEL_20:
  JUMPOUT(0x7A473E);
}
