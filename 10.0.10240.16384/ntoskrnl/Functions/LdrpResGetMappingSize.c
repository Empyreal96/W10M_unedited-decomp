// LdrpResGetMappingSize 
 
int __fastcall LdrpResGetMappingSize(unsigned int a1, unsigned int *a2, int a3, int a4)
{
  unsigned int v6; // r6
  unsigned int v7; // r4
  int v8; // r10
  int v9; // r0
  int v10; // r1
  unsigned int v11; // r5
  int v13; // r0
  _DWORD _14[21]; // [sp+14h] [bp-3Ch] BYREF

  _14[19] = a3;
  _14[20] = a4;
  _14[18] = a2;
  _14[17] = a1;
  if ( !a1 || !a2 )
    return -1073741811;
  v6 = 0;
  if ( (a3 & 0x20000) != 0 )
    v6 = *a2;
  *a2 = 0;
  v7 = 0;
  _14[2] = 0;
  v8 = 0;
  if ( (a3 & 0x100) != 0 && (a1 & 1) == 0 )
    v8 = 1;
  v9 = RtlImageNtHeaderEx(1, a1 & 0xFFFFFFFC, 0i64, _14);
  if ( v9 >= 0 )
  {
    v10 = *(unsigned __int16 *)(_14[0] + 24);
    if ( v10 == 267 || v10 == 523 )
    {
      v11 = *(_DWORD *)(_14[0] + 80);
    }
    else
    {
      v11 = 0;
      v9 = -1073741701;
      _14[1] = -1073741701;
    }
    if ( v9 >= 0 )
    {
      if ( !v8 || !v11 )
      {
        v13 = LdrpKrnGetDataTableEntry(a1);
        if ( v13 )
          v7 = *(_DWORD *)(v13 + 32);
        if ( v7 )
        {
          v9 = 0;
        }
        else
        {
          v9 = ZwQueryVirtualMemory();
          if ( v9 >= 0 )
            v7 = _14[6];
        }
        if ( v7 || !v11 )
          goto LABEL_27;
        v9 = 0;
      }
      v7 = v11;
LABEL_27:
      if ( v9 >= 0 )
      {
        if ( v6 && v6 < v7 )
          v9 = -1073741793;
        else
          *a2 = v7;
      }
      return v9;
    }
  }
  return v9;
}
