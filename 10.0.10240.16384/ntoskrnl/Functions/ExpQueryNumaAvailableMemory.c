// ExpQueryNumaAvailableMemory 
 
int __fastcall ExpQueryNumaAvailableMemory(_DWORD *a1, unsigned int a2, _DWORD *a3)
{
  int result; // r0
  unsigned int v6; // r1
  unsigned int v7; // r6
  unsigned int v8; // r5
  unsigned int v9; // r9
  unsigned int v10; // r0
  unsigned int v11; // lr
  unsigned __int64 v12; // kr08_8
  unsigned __int64 v13; // r2
  int v14; // r1
  unsigned int v15; // r0
  int v16; // [sp+0h] [bp-40h] BYREF
  int v17; // [sp+4h] [bp-3Ch]
  unsigned int v18; // [sp+8h] [bp-38h] BYREF
  unsigned int v19; // [sp+Ch] [bp-34h]
  unsigned int v20; // [sp+10h] [bp-30h]
  unsigned __int64 v21; // [sp+18h] [bp-28h]

  if ( a2 >= 4 )
  {
    v6 = (unsigned __int16)KeNumberNodes;
    *a1 = (unsigned __int16)KeNumberNodes - 1;
    v7 = (a2 - 8) >> 3;
    if ( v7 > v6 )
      v7 = v6;
    if ( a2 >= 8 && v7 )
    {
      *a3 = 8 * (v7 + 1);
      if ( v6 <= 1 )
      {
        v15 = MmGetAvailablePages();
        a1[2] = v15 << 12;
        a1[3] = v15 >> 20;
      }
      else
      {
        v8 = 0;
        v20 = 0;
        while ( v8 < v7 )
        {
          result = MmGetChannelInformation(v8, &v16, &v18);
          if ( result < 0 )
          {
            v16 = result;
            return result;
          }
          v9 = 0;
          v21 = 0i64;
          v10 = 0;
          v17 = 0;
          v11 = 0;
          v19 = 0;
          while ( v11 < v18 / 0x28 )
          {
            v12 = __PAIR64__(v10, v9) + *(_QWORD *)(v16 + 40 * v11 + 24) + *(_QWORD *)(v16 + 40 * v11 + 16);
            v10 = HIDWORD(v12);
            v17 = HIDWORD(v12);
            v9 = v12;
            v21 = v12;
            v19 = ++v11;
          }
          ExFreePoolWithTag(v16);
          v13 = (unsigned __int64)v9 << 12;
          v14 = HIDWORD(v13) | (v17 << 12);
          HIDWORD(v13) = &a1[2 * v8 + 2];
          *(_DWORD *)HIDWORD(v13) = v13;
          *(_DWORD *)(HIDWORD(v13) + 4) = v14;
          v20 = ++v8;
        }
      }
      result = 0;
    }
    else
    {
      *a3 = 4;
      result = 0;
      v16 = 0;
    }
  }
  else
  {
    if ( a3 )
      *a3 = 4;
    result = -1073741820;
    v16 = -1073741820;
  }
  return result;
}
