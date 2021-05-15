// ArbpUpdatePriority 
 
int __fastcall ArbpUpdatePriority(int result, unsigned int *a2)
{
  unsigned int v2; // r2
  unsigned int *v3; // r5
  unsigned int *v4; // r4
  unsigned __int64 v5; // r6
  unsigned int v6; // r2
  unsigned int v7; // r10
  unsigned __int64 v8; // kr08_8
  unsigned int v9; // r9
  unsigned int v10; // r2
  int v11; // kr18_4
  int v12; // r3
  char v13; // [sp+4h] [bp-2Ch]
  unsigned int v14; // [sp+Ch] [bp-24h]

  v2 = a2[8];
  if ( v2 == 2147483646 || v2 == 2147483645 )
    JUMPOUT(0x80E550);
  v13 = *(_BYTE *)a2[10];
  if ( v2 )
    return sub_80E530();
  v3 = *(unsigned int **)(result + 32);
  v4 = v3;
  v14 = (unsigned int)&v3[4 * *(unsigned __int16 *)(result + 28)];
  if ( (unsigned int)v3 >= v14 )
  {
LABEL_11:
    if ( (*(_BYTE *)a2[10] & 1) != 0 )
      a2[8] = 2147483645;
    else
      a2[8] = 2147483646;
  }
  else
  {
    v5 = *(_QWORD *)a2;
    while ( 1 )
    {
      result = v4[1];
      v6 = *v4;
      if ( (v5 >= *(_QWORD *)v4 || *((_QWORD *)a2 + 1) >= __PAIR64__(result, v6))
        && (__PAIR64__(result, v6) >= v5 || *((_QWORD *)v4 + 1) >= v5) )
      {
        v8 = *((_QWORD *)a2 + 1);
        v7 = v8;
        v9 = v4[3];
        if ( v8 >= *((_QWORD *)v4 + 1) )
          v7 = v4[2];
        else
          v9 = a2[3];
        if ( v5 > __PAIR64__(result, v6) )
        {
          result = a2[1];
          v6 = *a2;
        }
        v11 = v7 - v6 + 1;
        v10 = (__PAIR64__(v9, v7) - __PAIR64__(result, v6) + 1) >> 32;
        result = v11;
        if ( __PAIR64__(v10, v11) >= *((_QWORD *)a2 + 2) )
          break;
      }
      v4 += 4;
      if ( (unsigned int)v4 >= v14 )
        goto LABEL_11;
    }
    v12 = (((char *)v4 - (char *)v3) >> 4) + 1;
    a2[8] = v12;
    if ( (v13 & 1) != 0 )
      a2[8] = -v12;
  }
  return result;
}
