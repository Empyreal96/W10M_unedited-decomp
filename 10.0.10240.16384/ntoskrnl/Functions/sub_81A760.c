// sub_81A760 
 
void sub_81A760()
{
  int v0; // r4
  int v1; // r2

  v1 = *(_DWORD *)(v0 + 8);
  if ( *(_WORD *)(v1 + 28) == 12 && !wcsicmp(*(_DWORD *)(v1 + 32), L"PCMCIA") )
    JUMPOUT(0x7B7BFA);
  JUMPOUT(0x7B7BF2);
}
