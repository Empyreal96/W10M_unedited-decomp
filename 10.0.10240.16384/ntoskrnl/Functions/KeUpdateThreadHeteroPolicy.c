// KeUpdateThreadHeteroPolicy 
 
int __fastcall KeUpdateThreadHeteroPolicy(int result)
{
  int v1; // r2

  v1 = *(unsigned __int8 *)(result + 86);
  if ( (v1 & 0xFFFFFF80) == 0 && (v1 & 0x7F) == 8 )
    result = KiSetHeteroPolicyThread(result, 8, 1, 1);
  return result;
}
