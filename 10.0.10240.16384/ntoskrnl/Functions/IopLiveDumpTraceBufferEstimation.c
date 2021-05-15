// IopLiveDumpTraceBufferEstimation 
 
int IopLiveDumpTraceBufferEstimation()
{
  int result; // r0
  unsigned int *v1; // r1
  unsigned __int64 v2; // [sp+8h] [bp-70h] BYREF
  unsigned __int64 v3; // [sp+10h] [bp-68h] BYREF
  unsigned __int64 v4; // [sp+18h] [bp-60h] BYREF
  unsigned __int64 v5; // [sp+20h] [bp-58h] BYREF
  unsigned __int64 *v6; // [sp+28h] [bp-50h]
  int v7; // [sp+2Ch] [bp-4Ch]
  int v8; // [sp+30h] [bp-48h]
  int v9; // [sp+34h] [bp-44h]
  unsigned __int64 *v10; // [sp+38h] [bp-40h]
  int v11; // [sp+3Ch] [bp-3Ch]
  int v12; // [sp+40h] [bp-38h]
  int v13; // [sp+44h] [bp-34h]
  unsigned __int64 *v14; // [sp+48h] [bp-30h]
  int v15; // [sp+4Ch] [bp-2Ch]
  int v16; // [sp+50h] [bp-28h]
  int v17; // [sp+54h] [bp-24h]
  unsigned __int64 *v18; // [sp+58h] [bp-20h]
  int v19; // [sp+5Ch] [bp-1Ch]
  int v20; // [sp+60h] [bp-18h]
  int v21; // [sp+64h] [bp-14h]

  result = IopLiveDumpIsTracingEnabled();
  if ( result )
  {
    v3 = (unsigned __int64)v1[15] << 12;
    v5 = (unsigned __int64)v1[14] << 12;
    v2 = (unsigned __int64)v1[16] << 12;
    v4 = (unsigned __int64)v1[17] << 12;
    v6 = &v3;
    v7 = 0;
    v8 = 8;
    v9 = 0;
    v10 = &v5;
    v11 = 0;
    v12 = 8;
    v13 = 0;
    v14 = &v2;
    v15 = 0;
    v16 = 8;
    v17 = 0;
    v18 = &v4;
    v19 = 0;
    v20 = 8;
    v21 = 0;
    result = EtwWrite(
               IopLiveDumpEtwRegHandle,
               SHIDWORD(IopLiveDumpEtwRegHandle),
               (int)LIVEDUMP_EVENT_SIZING_WORKFLOW_BUFFER_ESTIMATION,
               0);
  }
  return result;
}
