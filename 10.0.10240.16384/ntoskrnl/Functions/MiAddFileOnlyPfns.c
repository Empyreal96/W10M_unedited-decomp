// MiAddFileOnlyPfns 
 
int __fastcall MiAddFileOnlyPfns(int a1, unsigned int a2)
{
  unsigned __int64 v3; // kr08_8
  int result; // r0
  __int64 v5; // [sp+0h] [bp-20h] BYREF
  unsigned __int64 v6; // [sp+8h] [bp-18h] BYREF

  v6 = (unsigned __int64)(unsigned int)a1 << 12;
  v3 = (unsigned __int64)a2 << 12;
  v5 = v3;
  result = MiAddPhysicalMemory(a1, &v6, &v5, 2);
  if ( result >= 0 && v5 != v3 )
  {
    LODWORD(v6) = v5 >> 11;
    MiRemovePhysicalMemory(a1, v5 / 4096, 2);
    result = -1073741585;
  }
  return result;
}
