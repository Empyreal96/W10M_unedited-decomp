// MiCheckForUserStackOverflow 
 
int __fastcall MiCheckForUserStackOverflow(unsigned int a1, int a2)
{
  unsigned int v2; // r6
  int v3; // r2
  _DWORD *v4; // r3
  unsigned int v5; // r5
  unsigned int v6; // r2
  unsigned int *v7; // r9
  unsigned int v8; // r1
  int v9; // r0
  unsigned int v10; // r3
  int result; // r0
  int v12; // [sp+8h] [bp-40h]
  unsigned int v13; // [sp+Ch] [bp-3Ch]
  unsigned int v14; // [sp+Ch] [bp-3Ch]

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = *(unsigned __int8 *)(v2 + 0x3C8);
  if ( (v3 & 0xFFFFFF80) == 128
    || (v3 & 2) != 0
    || (v3 & 1) != 0
    || *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1 )
  {
    return -2147483647;
  }
  v4 = *(_DWORD **)(v2 + 156);
  v5 = v4[899] & 0xFFFFF000;
  v6 = (v4[990] + 4095) & 0xFFFFF000;
  v12 = v6;
  v7 = v4 + 2;
  if ( v6 )
  {
    v6 += 4096;
    v12 = v6;
  }
  if ( v6 < 0x2000 )
  {
    v6 = 0x2000;
    v12 = 0x2000;
  }
  if ( a1 < v4[1] && a1 >= v5 )
  {
    v8 = (a1 & 0xFFFFF000) - v6;
    v13 = v8;
    if ( v8 > v5 )
    {
      if ( (*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v2 + 116) + 320) + 104) & 0x10000) != 0 )
      {
        v9 = -1073741523;
      }
      else
      {
        v9 = ZwAllocateVirtualMemory();
        v6 = v12;
        v8 = v13;
      }
      if ( v9 >= 0 )
      {
        v10 = v8 + v6;
        result = 275;
LABEL_20:
        *v7 = v10;
        return result;
      }
      v14 = v8 + 4096;
    }
    else
    {
      v14 = v5 + 4096;
    }
    ZwProtectVirtualMemory();
    v10 = v14;
    result = -1073741571;
    goto LABEL_20;
  }
  return -2147483647;
}
