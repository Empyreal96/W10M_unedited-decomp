// MiStartZeroPageWorkers 
 
void MiStartZeroPageWorkers()
{
  int v0; // r4
  int v1; // r1
  char v2; // r9
  int v3; // r8
  int v4; // r6
  int v5; // [sp+18h] [bp-38h] BYREF
  __int16 v6; // [sp+1Ch] [bp-34h] BYREF
  int v7[12]; // [sp+20h] [bp-30h] BYREF

  v0 = 0;
  if ( KeNumberNodes )
  {
LABEL_2:
    KeQueryNodeActiveAffinity((unsigned __int16)v0, v7, &v6);
    v2 = byte_6337F5;
    v3 = 0;
    while ( 1 )
    {
      v4 = MiCreateZeroThreadContext((int)MiSystemPartition, v1, v0 << v2);
      if ( !v4 )
        break;
      if ( PsCreateSystemThreadEx((int)&v5, 0x1FFFFF, 0, 0, 0, (int)MiZeroLargePageThread, v4, 0, 0) < 0 )
      {
        sub_96A990();
        return;
      }
      ObCloseHandle(v5);
      if ( ++v3 )
      {
        if ( ++v0 < (unsigned int)(unsigned __int16)KeNumberNodes )
          goto LABEL_2;
        return;
      }
    }
  }
}
