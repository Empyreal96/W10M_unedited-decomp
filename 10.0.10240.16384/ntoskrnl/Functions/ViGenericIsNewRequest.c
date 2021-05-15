// ViGenericIsNewRequest 
 
BOOL __fastcall ViGenericIsNewRequest(unsigned __int8 *a1, unsigned __int8 *a2)
{
  return !a1 || *a2 != *a1 || a2[1] != a1[1];
}
