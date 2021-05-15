// MiInitializeCombining 
 
void __fastcall MiInitializeCombining(int a1, _DWORD *a2)
{
  int v2; // r3

  *a2 = MiSystemPartition;
  if ( !dword_6403D4 )
  {
    dword_6403D8 = (int)&dword_6403D4;
    dword_6403D4 = (int)&dword_6403D4;
  }
  a2[9] = a2 + 9;
  a2[10] = a2 + 9;
  a2[11] = 0;
  v2 = 16;
  do
  {
    a2[12] = 0;
    __dmb(0xBu);
    a2[13] = 0;
    a2 += 2;
    --v2;
  }
  while ( v2 );
}
