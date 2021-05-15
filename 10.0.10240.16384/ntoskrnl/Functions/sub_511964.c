// sub_511964 
 
void __fastcall sub_511964(int a1, int a2, unsigned int a3)
{
  if ( ((*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C4) & 2) == 0 || a3 < 2) && (a1 == a2 || a3 < 2) )
    JUMPOUT(0x42A980);
  JUMPOUT(0x42A8FC);
}
