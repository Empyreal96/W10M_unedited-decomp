// MiUpdateSessionPdeMaster 
 
int __fastcall MiUpdateSessionPdeMaster(int a1, int a2)
{
  int v2; // r5
  _DWORD *v3; // r1

  v2 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
  v3 = (_DWORD *)(*(_DWORD *)(v2 + 0x2000) + 4 * ((unsigned int)(a1 - dword_63389C) >> 22));
  if ( (unsigned int)v3 >= 0xC0000000 )
    return sub_510220();
  *v3 = a2;
  return *(_DWORD *)(v2 + 24);
}
