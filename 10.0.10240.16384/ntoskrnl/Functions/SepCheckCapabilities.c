// SepCheckCapabilities 
 
int __fastcall SepCheckCapabilities(int a1, unsigned int a2, int a3, int a4, char *a5)
{
  int v7; // r5
  unsigned int v8; // r4
  char v9; // r5
  unsigned int v10; // r6
  unsigned int v11; // r10
  unsigned int v12; // r9
  unsigned __int16 *v13; // r3
  unsigned int v14; // r7
  unsigned __int16 *v16; // [sp+0h] [bp-28h] BYREF
  unsigned int v17; // [sp+4h] [bp-24h]
  int v18; // [sp+8h] [bp-20h]

  v18 = a4;
  v16 = 0;
  *a5 = 0;
  v17 = a2;
  v7 = SeQueryInformationToken(a1, 30, &v16);
  v8 = (unsigned int)v16;
  v18 = v7;
  if ( v7 >= 0 )
  {
    v9 = 1;
    v10 = 0;
    if ( a2 )
    {
      v11 = *(_DWORD *)v16;
      do
      {
        v9 = 0;
        v12 = 0;
        if ( !v11 )
          break;
        v13 = *(unsigned __int16 **)a3;
        v14 = v8 + 4;
        v16 = *(unsigned __int16 **)a3;
        while ( !RtlEqualSid(*(unsigned __int16 **)v14, v13) || *(_DWORD *)(v14 + 4) != *(_DWORD *)(a3 + 4) )
        {
          ++v12;
          v14 += 8;
          if ( v12 >= v11 )
            goto LABEL_11;
          v13 = v16;
        }
        ++v10;
        v9 = 1;
        a3 += 8;
      }
      while ( v10 < v17 );
    }
LABEL_11:
    *a5 = v9;
    v7 = v18;
  }
  if ( v8 )
    ExFreePoolWithTag(v8);
  return v7;
}
