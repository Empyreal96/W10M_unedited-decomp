// MiCheckBadSystemProcessAccess 
 
int __fastcall MiCheckBadSystemProcessAccess(unsigned __int64 a1, char a2)
{
  if ( (unsigned int)a1 >= 0x10000 && a1 <= (unsigned int)(MmHighestUserAddress - 0x10000) && (a2 & 1) != 0 )
    LODWORD(a1) = sub_52636C();
  return a1;
}
