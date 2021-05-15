// MmQueryMemoryListInformation 
 
int __fastcall MmQueryMemoryListInformation(int a1, unsigned int a2, int a3, _DWORD *a4)
{
  int v6; // r4
  unsigned int v7; // r1
  __int16 *v8; // r4
  unsigned int i; // r0
  char *v10; // r2
  unsigned int v11; // r3
  unsigned int v12; // r3
  unsigned int v13; // r1
  unsigned int v14; // r3
  unsigned int v15; // r3
  unsigned int v16; // r2
  unsigned int *v17; // r3
  int v18; // r1
  unsigned int v19; // r0
  unsigned int v21; // [sp+8h] [bp-70h] BYREF
  unsigned int v22; // [sp+Ch] [bp-6Ch]
  unsigned int v23; // [sp+10h] [bp-68h]
  unsigned int v24; // [sp+14h] [bp-64h]
  unsigned int v25; // [sp+18h] [bp-60h]
  unsigned int v26; // [sp+5Ch] [bp-1Ch]

  *a4 = 0;
  if ( a2 >= 0x58 )
  {
    v7 = dword_640508;
    v21 = dword_63FB80;
    v22 = dword_63FC00;
    v23 = dword_640680;
    v24 = dword_640700;
    v25 = dword_640080;
    v26 = dword_640718;
    v8 = MiSystemPartition;
    for ( i = 0; i < 16; i += 2 )
    {
      v10 = (char *)&v21 + i * 2;
      *((_DWORD *)v10 + 5) = *((_DWORD *)v8 + 384);
      *((_DWORD *)v10 + 13) = *(_DWORD *)&MiSystemPartition[i + 1242];
      v8 += 10;
    }
    if ( v21 <= v7 )
    {
      v11 = v7 - v21;
    }
    else
    {
      v21 = v7;
      v11 = 0;
    }
    if ( v22 <= v11 )
    {
      v12 = v11 - v22;
    }
    else
    {
      v22 = v11;
      v12 = 0;
    }
    v13 = v23;
    if ( v23 <= v12 )
    {
      v14 = v12 - v23;
    }
    else
    {
      v13 = v12;
      v23 = v12;
      v14 = 0;
    }
    if ( v24 <= v14 )
    {
      v15 = v14 - v24;
    }
    else
    {
      v24 = v14;
      v15 = 0;
    }
    if ( v25 <= v15 )
    {
      v16 = v15 - v25;
    }
    else
    {
      v25 = v15;
      v16 = 0;
    }
    if ( v26 >= v13 )
      v26 = v13;
    v17 = &v21;
    v18 = 8;
    do
    {
      v19 = v17[5];
      if ( v19 <= v16 )
      {
        v16 -= v19;
      }
      else
      {
        v17[5] = v16;
        v16 = 0;
      }
      ++v17;
      --v18;
    }
    while ( v18 );
    v6 = 0;
    memmove(a1, (int)&v21, 0x58u);
    *a4 = 88;
  }
  else
  {
    *a4 = 88;
    v6 = -1073741820;
  }
  return v6;
}
