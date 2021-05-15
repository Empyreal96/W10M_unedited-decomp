// PfTAcquireEntryInfo 
 
int __fastcall PfTAcquireEntryInfo(int a1, int a2, _WORD *a3, char *a4)
{
  char v7; // r7
  int v8; // r4
  int v9; // r0
  int result; // r0
  __int16 v11[2]; // [sp+0h] [bp-20h] BYREF
  char *v12; // [sp+4h] [bp-1Ch]
  int varg_r0; // [sp+28h] [bp+8h]
  int varg_r1; // [sp+2Ch] [bp+Ch]
  _WORD *varg_r2; // [sp+30h] [bp+10h]
  char *varg_r3; // [sp+34h] [bp+14h]

  varg_r0 = a1;
  varg_r2 = a3;
  varg_r3 = a4;
  v11[1] = HIWORD(a3);
  v12 = a4;
  v11[0] = 0;
  varg_r1 = a2;
  v7 = 0;
  while ( 1 )
  {
    v8 = *(_DWORD *)(a1 + 16);
    v9 = PfTEntryInfoLookup(v8, a2, v11);
    if ( v9 != 0xFFFF )
      break;
    if ( *(_DWORD *)(v8 + 20) < (unsigned int)(3 * (*(_DWORD *)(v8 + 24) >> 2)) )
    {
      v9 = (unsigned __int16)v11[0];
      ++*(_DWORD *)(v8 + 20);
      v7 = 1;
      *(_DWORD *)(((v8 + 35) & 0xFFFFFFFC) + 20 * v9) = varg_r1;
      break;
    }
    if ( PfTReplaceCurrentBuffer(a1) == -1073741823 )
    {
      v8 = 0;
      LOWORD(v9) = -1;
      break;
    }
    a2 = varg_r1;
  }
  *a3 = v9;
  result = v8;
  *a4 = v7;
  return result;
}
