// BvgaDriverInitialize 
 
int __fastcall BvgaDriverInitialize(int a1, int a2, unsigned int a3)
{
  int result; // r0
  char *v6; // r0
  char *v7; // r0
  unsigned int v8; // r6
  int v9; // r4
  int v10; // r0
  unsigned int v11; // r3

  if ( BvgaBootDriverFullyInitialized == 1 )
    return 1;
  BootDriverLock = 0;
  if ( a1 == 1 && !BvgaDisplayState )
  {
    v6 = *(char **)(a2 + 120);
    v7 = v6 ? strupr(v6) : 0;
    if ( v7 )
      strstr(v7, "BOOTLOGO");
  }
  result = VidInitialize_0();
  BvgaBootDriverInstalled = result;
  if ( !result )
    return 0;
  if ( a1 == 1 )
  {
    BvgaBootDriverFullyInitialized = 1;
    ResourceCount = a3;
    if ( a3 > 7 )
    {
      a3 = 7;
      ResourceCount = 7;
    }
    v8 = 1;
    if ( a3 )
    {
      v9 = 0;
      do
      {
        v10 = FindBitmapResource(v8, (char *)&ResourceSize + v9 * 4);
        v11 = ResourceCount;
        ResourceList[v9] = v10;
        ++v8;
        ++v9;
      }
      while ( v8 <= v11 );
    }
    BvgaSaveResources();
    result = (unsigned __int8)BvgaBootDriverInstalled;
    BvgaProgressState = 0;
    dword_631C04 = 10000;
    dword_631C08 = 100;
  }
  return result;
}
