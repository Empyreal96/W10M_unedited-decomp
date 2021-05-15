// SdbReadGUIDTag 
 
_DWORD *__fastcall SdbReadGUIDTag(_DWORD *a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  _DWORD *varg_r0; // [sp+18h] [bp+8h]

  varg_r0 = a1;
  if ( !SdbReadBinaryTag(a2, a3, (int)a1, 0x10u) )
  {
    AslLogCallPrintf(1, (int)"SdbReadGUIDTag", 146, "Failed to read GUID");
    *a1 = a4;
    a1[1] = a5;
    a1[2] = a6;
    a1[3] = a7;
  }
  return a1;
}
