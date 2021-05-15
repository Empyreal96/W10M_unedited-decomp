// IopInitializeReserveIrps 
 
int IopInitializeReserveIrps()
{
  int v0; // r5
  _DWORD *v1; // r0

  byte_631964 = 42;
  IopReserveIrps = IopAllocateIrpWithExtension(0, 42, 0);
  if ( IopReserveIrps )
  {
    dword_6318E4 = 0;
    byte_6318E8 = 1;
    byte_6318E9 = 0;
    byte_6318EA = 4;
    dword_6318EC = 0;
    dword_6318F4 = (int)&dword_6318F0;
    dword_6318F0 = (int)&dword_6318F0;
    dword_6318F8 = IopAllocateIrpWithExtension(0, 42, 0);
    if ( dword_6318F8 )
    {
      dword_6318FC = 0;
      byte_631900 = 1;
      byte_631901 = 0;
      byte_631902 = 4;
      dword_631904 = 0;
      dword_63190C = (int)&dword_631908;
      dword_631908 = (int)&dword_631908;
      dword_631910 = IopAllocateIrpWithExtension(0, 42, 0);
      if ( dword_631910 )
      {
        dword_631914 = 0;
        byte_631918 = 1;
        byte_631919 = 0;
        byte_63191A = 4;
        dword_63191C = 0;
        dword_631924 = (int)&dword_631920;
        dword_631920 = (int)&dword_631920;
        dword_631960 = 0;
        v0 = 0;
        while ( 1 )
        {
          v1 = (_DWORD *)IopAllocateIrpWithExtension(0, 42, 0);
          if ( !v1 )
            break;
          if ( v0 )
          {
            if ( v0 == 1 )
            {
              dword_631944 = (int)v1;
            }
            else
            {
              *v1 = dword_631960;
              dword_631960 = (int)v1;
            }
          }
          else
          {
            dword_631928 = (int)v1;
          }
          if ( (unsigned int)++v0 >= 8 )
          {
            dword_63192C = 0;
            dword_631948 = 0;
            dword_631930 = 0;
            dword_63194C = 0;
            byte_631934 = 1;
            byte_631935 = 0;
            byte_631936 = 4;
            dword_631938 = 0;
            dword_631940 = (int)&dword_63193C;
            dword_63193C = (int)&dword_63193C;
            byte_631950 = 1;
            byte_631951 = 0;
            byte_631952 = 4;
            dword_631954 = 0;
            dword_63195C = (int)&dword_631958;
            dword_631958 = (int)&dword_631958;
            return 1;
          }
        }
      }
    }
  }
  return 0;
}
