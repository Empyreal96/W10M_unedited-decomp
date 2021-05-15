// sub_517B78 
 
void __fastcall sub_517B78(int a1, int a2, unsigned int a3, int a4, int a5)
{
  int v5; // r4
  unsigned int v6; // r5
  unsigned int v7; // r2
  _DWORD *v8; // r1
  unsigned int v9; // r3
  unsigned int v10; // r5
  unsigned int v11; // r2
  int *v12; // r1
  unsigned int v13; // r3

  if ( a4 == 4 )
  {
    v10 = (a3 + 7) & 0xFFFFFFF8;
    if ( v10 < a3 )
      goto LABEL_23;
    if ( RtlULongLongToULong(16 * *(_DWORD *)(v5 + 36), (unsigned __int64)*(unsigned int *)(v5 + 36) >> 28, &a5) >= 0 )
    {
      v11 = a5 + v10;
      if ( a5 + v10 >= v10 )
      {
        v12 = *(int **)(v5 + 44);
        while ( v12 != (int *)(v5 + 44) )
        {
          v13 = *((unsigned __int16 *)v12 + 16) + v11;
          if ( v13 < v11 )
            goto LABEL_23;
          v12 = (int *)*v12;
          v11 = v13;
        }
LABEL_25:
        JUMPOUT(0x439E36);
      }
LABEL_23:
      JUMPOUT(0x439E7E);
    }
  }
  else
  {
    if ( a4 != 5 )
    {
      if ( a4 == 6 )
        JUMPOUT(0x439E14);
      if ( a4 != 16 )
        JUMPOUT(0x439E82);
    }
    v6 = (a3 + 3) & 0xFFFFFFFC;
    if ( v6 < a3 )
      goto LABEL_23;
    if ( RtlULongLongToULong(8 * *(_DWORD *)(v5 + 36), (unsigned __int64)*(unsigned int *)(v5 + 36) >> 29, &a5) >= 0 )
    {
      v7 = a5 + v6;
      if ( a5 + v6 >= v6 )
      {
        v8 = *(_DWORD **)(v5 + 44);
        while ( v8 != (_DWORD *)(v5 + 44) )
        {
          v9 = v8[7] + v7;
          if ( v9 < v7 )
            goto LABEL_23;
          v8 = (_DWORD *)*v8;
          v7 = v9;
        }
        goto LABEL_25;
      }
      goto LABEL_23;
    }
  }
  JUMPOUT(0x439E3A);
}
