// IopLiveDumpTraceBufferAllocation 
 
int IopLiveDumpTraceBufferAllocation()
{
  int result; // r0
  _DWORD *v1; // r1
  unsigned __int64 v2; // [sp+8h] [bp-58h] BYREF
  int v3[2]; // [sp+10h] [bp-50h] BYREF
  unsigned __int64 v4; // [sp+18h] [bp-48h] BYREF
  unsigned __int64 *v5; // [sp+20h] [bp-40h]
  int v6; // [sp+24h] [bp-3Ch]
  int v7; // [sp+28h] [bp-38h]
  int v8; // [sp+2Ch] [bp-34h]
  unsigned __int64 *v9; // [sp+30h] [bp-30h]
  int v10; // [sp+34h] [bp-2Ch]
  int v11; // [sp+38h] [bp-28h]
  int v12; // [sp+3Ch] [bp-24h]
  int *v13; // [sp+40h] [bp-20h]
  int v14; // [sp+44h] [bp-1Ch]
  int v15; // [sp+48h] [bp-18h]
  int v16; // [sp+4Ch] [bp-14h]

  result = IopLiveDumpIsTracingEnabled();
  if ( result )
  {
    v4 = (unsigned __int64)(unsigned int)v1[69] << 12;
    v2 = (unsigned __int64)(unsigned int)v1[70] << 12;
    v3[0] = v1[19];
    v3[1] = 0;
    v5 = &v4;
    v6 = 0;
    v7 = 8;
    v8 = 0;
    v9 = &v2;
    v10 = 0;
    v11 = 8;
    v12 = 0;
    v13 = v3;
    v14 = 0;
    v15 = 8;
    v16 = 0;
    result = EtwWrite(
               IopLiveDumpEtwRegHandle,
               SHIDWORD(IopLiveDumpEtwRegHandle),
               (int)LIVEDUMP_EVENT_SIZING_WORKFLOW_BUFFER_ALLOCATION,
               0);
  }
  return result;
}
