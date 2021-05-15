// MiBytesForFixupVad 
 
int __fastcall MiBytesForFixupVad(int a1)
{
  return 4 * (((*(_DWORD *)(*(_DWORD *)a1 + 4) & 0x1F) != 0) + (*(_DWORD *)(*(_DWORD *)a1 + 4) >> 5) + 22);
}
