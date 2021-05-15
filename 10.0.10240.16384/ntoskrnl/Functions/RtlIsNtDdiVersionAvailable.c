// RtlIsNtDdiVersionAvailable 
 
BOOL __fastcall RtlIsNtDdiVersionAvailable(unsigned int a1)
{
  return (a1 & 0xFF00) == 0 && !(_BYTE)a1 && a1 <= 0xA000000;
}
