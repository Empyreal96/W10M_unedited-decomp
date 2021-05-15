// SmKmVolumeQueryUniqueId 
 
int __fastcall SmKmVolumeQueryUniqueId(int a1, unsigned __int16 *a2, int a3)
{
  int v6; // r7
  int v7; // r2
  int v8; // r3
  int v9; // r4
  unsigned int v10; // r2
  unsigned int v11; // r4

  v6 = IoSetThreadHardErrorMode(0);
  v9 = SmKmSendDeviceControl(v6, a1, v7, v8, (int)a2, a3);
  if ( v9 >= 0 )
  {
    v10 = *a2;
    v11 = v10 >> 1;
    if ( v10 >> 1 )
    {
      memmove((int)a2, (int)(a2 + 1), v10);
      SmSanitizeString((unsigned int)a2, 2 * (v11 + 1));
      v9 = 0;
    }
    else
    {
      v9 = -1073740730;
    }
  }
  IoSetThreadHardErrorMode(v6);
  return v9;
}
