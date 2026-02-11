namespace PcDebugGui.Core.Models;

public static class FocParameterCatalog
{
    // Mirrors st_rmw_param_buffer_t in app/rmw/r_app_rmw.h
    public static IReadOnlyList<FocParameterDefinition> Items { get; } =
    [
        new("u2_offset_calc_time", "Offset", "100us", "Current offset calculation time"),
        new("f4_max_speed_rpm", "Motor", "rpm", "Maximum mechanical speed"),
        new("u1_ctrl_loop_mode", "Sensorless", "-", "Loop mode select"),
        new("f4_ol_ref_id", "Sensorless", "A", "Id reference in open loop"),
        new("f4_id_up_time", "Sensorless", "s", "Time to increase Id"),
        new("f4_id_down_time", "Sensorless", "s", "Time to decrease Id"),
        new("f4_id_down_speed_rpm", "Sensorless", "rpm", "Speed threshold to ramp Id down"),
        new("f4_id_up_speed_rpm", "Sensorless", "rpm", "Speed threshold to ramp Id up"),
        new("f4_current_omega_hz", "CurrentControl", "Hz", "Current loop natural frequency"),
        new("f4_current_zeta", "CurrentControl", "-", "Current loop damping ratio"),
        new("f4_speed_omega_hz", "SpeedControl", "Hz", "Speed loop natural frequency"),
        new("f4_speed_zeta", "SpeedControl", "-", "Speed loop damping ratio"),
        new("f4_speed_lpf_hz", "SpeedControl", "Hz", "Speed LPF frequency"),
        new("f4_ref_speed_rpm", "SpeedControl", "rpm", "Reference mechanical speed"),
        new("f4_speed_rate_limit_rpm", "SpeedControl", "rpm/s", "Reference change limit"),
        new("f4_overspeed_limit_rpm", "SpeedControl", "rpm", "Overspeed limit"),
        new("u1_flag_volt_err_comp_use", "Optional", "-", "Enable voltage error compensation"),
        new("u1_flag_fluxwkn_use", "Optional", "-", "Enable flux-weakening"),
        new("f4_e_obs_omega_hz", "Observer", "Hz", "BEMF observer natural frequency"),
        new("f4_e_obs_zeta", "Observer", "-", "BEMF observer damping ratio"),
        new("f4_pll_est_omega_hz", "Observer", "Hz", "PLL natural frequency"),
        new("f4_pll_est_zeta", "Observer", "-", "PLL damping ratio"),
        new("u1_flag_less_switch_use", "Switch", "-", "Enable sensorless switch control"),
        new("f4_switch_phase_err_deg", "Switch", "deg", "Phase error threshold"),
        new("f4_opl2less_sw_time", "Switch", "s", "Open-loop to sensorless switch time"),
        new("f4_phase_err_lpf_cut_freq", "Switch", "Hz", "Phase error LPF cutoff"),
        new("u1_flag_openloop_damping_use", "OpenLoopDamping", "-", "Enable open-loop damping"),
        new("f4_ed_hpf_omega", "OpenLoopDamping", "Hz", "ed HPF cutoff"),
        new("f4_ol_damping_zeta", "OpenLoopDamping", "-", "Damping ratio"),
        new("f4_ol_damping_fb_limit_rate", "OpenLoopDamping", "-", "Feedback speed limit rate"),
    ];
}
