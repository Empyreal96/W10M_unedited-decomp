// EtwpCreatePerfectHashFunction 
 
int __fastcall EtwpCreatePerfectHashFunction(int a1, int a2, int a3, int *a4)
{
  int v4; // r4
  unsigned int v5; // r8
  unsigned int v6; // r6
  int v8; // lr
  int i; // r9
  unsigned __int16 v10; // r7
  unsigned int v11; // r5
  unsigned int v12; // r0
  unsigned int v13; // r4
  int v14; // r0
  int v16; // r3
  int v17; // r1
  unsigned __int8 j; // r5
  __int16 v19; // [sp+8h] [bp-230h] BYREF
  int v20; // [sp+Ch] [bp-22Ch]
  int v21; // [sp+10h] [bp-228h]
  int *v22; // [sp+14h] [bp-224h]
  _DWORD v23[136]; // [sp+18h] [bp-220h] BYREF

  v21 = a1;
  v22 = a4;
  v4 = 1;
  v19 = 0;
  v5 = 0;
  v6 = 0;
  v8 = a2;
  v20 = a2;
  for ( i = 63; v4 < a3 - 1; v4 = (unsigned __int16)(2 * v4) | 1 )
    ;
  v10 = v4;
  if ( (unsigned int)v4 > 0x40 )
    return -1073741823;
LABEL_4:
  v11 = 0;
  while ( 1 )
  {
    v12 = EtwpGetDirectMappingCount(v8, a3, v23, v4, v11);
    if ( v12 > v6 )
    {
      v6 = v12;
      v5 = v11;
      i = v4;
    }
    if ( v12 == a3 )
      break;
    v11 = (unsigned __int8)(v11 + 1);
    v8 = v20;
    if ( v11 >= 0x10 )
    {
      v8 = v20;
      v10 = (2 * v10) | 1;
      v4 = v10;
      if ( v10 <= 0x40u )
        goto LABEL_4;
      break;
    }
  }
  if ( !v6 )
    return -1073741823;
  v13 = ((int (__fastcall *)(int, int, unsigned int, int, _DWORD *, __int16 *))EtwpFillPerfectHashTable)(
          v20,
          a3,
          v5,
          i,
          v23,
          &v19);
  v14 = ExAllocatePoolWithTag(512, (unsigned __int16)(4 * v13 + 10), 1182233669);
  if ( !v14 )
    return -1073741801;
  v16 = v21;
  *(_BYTE *)(v14 + 1) = v5;
  *(_WORD *)(v14 + 2) = i;
  *(_WORD *)(v14 + 4) = v13;
  v17 = 0;
  *(_BYTE *)v14 = v16 != 0;
  if ( v13 )
  {
    for ( j = 0; j < v13; v17 = ++j )
      *(_DWORD *)(v14 + 4 * v17 + 6) = v23[v17];
  }
  *v22 = v14;
  return 0;
}
