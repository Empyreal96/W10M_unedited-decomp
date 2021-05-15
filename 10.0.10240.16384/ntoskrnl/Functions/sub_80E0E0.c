// sub_80E0E0 
 
void sub_80E0E0()
{
  int v0; // r4
  char v1; // r6

  *(_BYTE *)(v0 + 52) = v1 & 0xFE;
  (*(void (__fastcall **)(_DWORD, int, _DWORD))(*(_DWORD *)(v0 + 12) + 16))(*(_DWORD *)(*(_DWORD *)(v0 + 12) + 4), 3, 0);
  JUMPOUT(0x796162);
}
