// LdrpArmProcessRelocation 
 
int __fastcall LdrpArmProcessRelocation(unsigned __int16 *a1, int a2, int a3)
{
  int v3; // r0
  int v4; // r6
  int v5; // r3
  unsigned int v6; // r0
  int v7; // r7
  unsigned int v8; // r3

  v3 = *a1;
  v4 = 1;
  v5 = v3 & 0xFFC;
  v6 = v3 & 0xFFFFF000;
  v7 = v5 + a2;
  if ( v6 != 20480 )
    v4 = 0;
  if ( v6 == 20480 )
  {
    v8 = ((unsigned __int16)*(_QWORD *)v7 ^ (unsigned __int16)(*(_DWORD *)v7 >> 4)) & 0xFFF ^ (unsigned __int16)(*(_DWORD *)v7 >> 4) | (((*(_DWORD *)(v7 + 4) >> 4) & 0xFFFFF000 | *(_DWORD *)(v7 + 4) & 0xFFF) << 16);
    *(_DWORD *)v7 = *(_DWORD *)v7 & 0xFFF0F000 | ((_WORD)v8 + (_WORD)a3) & 0xFFF | (16 * ((v8 + a3) & 0xF000));
    *(_DWORD *)(v7 + 4) = *(_DWORD *)(v7 + 4) & 0xFFF0F000 | (16 * (((v8 + a3) >> 16) & 0xF000)) | ((v8 + a3) >> 16) & 0xFFF;
  }
  return v4;
}
